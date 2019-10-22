basename $(find . -type f -name "*.sh") | rev | sed "s/\hs.//" | rev 
