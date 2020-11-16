LOGS_FOLDER=logs
ERROR_LOG=$LOGS_FOLDER/$(date +"%Y-%m-%d__%H:%M:%S").logs

clear;
if [ ! -d logs ];
then
    mkdir logs;
fi;

if [ ! -z $1 ] && [ $1 == --logs ];
then
    rm -rf $LOGS_FOLDER/*;
else
    printf "\e[1;31m If you want to delete old logs, exec: $0 --logs\n\n"
    sleep 2;
fi

print() {
    printf "$1$2\e[0m"
    printf "$2\n" >> $ERROR_LOG
}
# Initialize minikube

clear;
print "\e[1;34m" "Checking minikube's status";

if ! minikube status >> /dev/null 2>>$ERROR_LOG; then
    print "\33[2K\r\e[1;33m" "Starting minikube\n\n";
    minikube delete;
    minikube start --driver=virtualbox;
    print "\n\e[1;32m" "Minikube started\n";
else
    print "\33[2K\r\e[1;32m" "Minikube already started\n"
fi;

# Set docker environment to minikube's
print "\e[1;33m" "Setting minikube env"
eval $(minikube docker-env)
print "\33[2K\r\e[1;32m" "Minikube env setted\n\n"

# Add metalLB loadBalancer
print "\e[1;33m" "Adding a real loadBalancer (metalLB)\n"
kubectl get configmap kube-proxy -n kube-system -o yaml | \
sed -e "s/strictARP: false/strictARP: true/" > /dev/null 2>>$ERROR_LOG

# actually apply the changes, returns nonzero returncode on errors only
kubectl get configmap kube-proxy -n kube-system -o yaml | \
sed -e "s/strictARP: false/strictARP: true/" | \
kubectl apply -f - -n kube-system

kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.5/manifests/namespace.yaml
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.5/manifests/metallb.yaml

# On first install only
kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)"

kubectl apply -f srcs/metalLB/metalLB.yaml
print "\e[1;32m" "Added a real loadBalancer (metalLB)\n\n"

print "\e[1;33m" "Building nginx image\n"
docker build -t nginx:alpine srcs/nginx
print "\e[1;32m" "Nginx image builded\n\n"

print "\e[1;33m" "Create deployment nginx\n"
kubectl apply -f srcs/nginx/nginx.yaml
print "\e[1;32m" "Nginx deployment created\n\n"

sleep 2;
print "\e[1;33m" "Starting minikube dashboard\n"
minikube addons enable metrics-server
minikube addons enable dashboard
print "\e[1;33m" "Minikube dashboard enabled\n\n"
sleep 1;
clear;

print "\e[1;34m" "Open dashboard: \e[1;35mhttp://127.0.0.1:8001/api/v1/namespaces/kubernetes-dashboard/services/http:kubernetes-dashboard:/proxy\n"
kubectl proxy --port=8001;