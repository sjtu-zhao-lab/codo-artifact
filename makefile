clean:
	rm -rf $(shell pwd)/build/*


# Build docker container
build-docker: 
	(cd Docker; docker build . --tag codo:codo-temp)

# Enter docker container
shell: build-docker
	docker run -it -v $(shell pwd):/home/xzzhang/code/temp codo:codo-temp /bin/bash 