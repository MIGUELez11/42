# See kubernetes running nodes
kubectl get nodes

# Create a deployment
kubectl create deployment $deploy-name --image=$image_direction:$version

# Get Deployments
kubectl get deployments

# Get the kubectl proxy
kubectl proxy;
curl http://localhost:8001/version

# Get POD_NAMES
export POD_NAME=$(kubectl get pods -o go-template --template '{{range .items}}{{.metadata.name}}{{"\n"}}{{end}}')

# Get PODS
kubectl get pods

# Get PODS info
kubectl describe pods

# See logs of POD
kubectl logs $POD_NAME

# Exec command on POD
kubectl exec $POD_NAME -- $CMD

# Exec cmd on POD interactively
kubectl exec $POD_NAME -ti -- $CMD

# Get Services
kubectl get services

# Expose a port for deploy
kubectl expose deployment $NODE_NAME --type="NodePort" --port $PORT

# Get external port
kubectl get services/$NODE_NAME

# Get pod by label
kubectl get pods -l $key=$value

# Set label
kubectl label pod|service|... $NAME $key=$value

# Delete a service
kubectl delete service $Service_name
