#!/bin/bash

# --- Configuration ---
VITIS_HOST_PATH="/home/tools/Vitis_2023.2" 

PROJECT_ROOT=$(pwd)

IMAGE_NAME="codo_ae_image:v2"
CONTAINER_NAME="codo_ae_container_v2"

LOCALE_ENV="-e LANG=en_US.UTF-8 -e LC_ALL=en_US.UTF-8"

# --- Logic ---

if [ "$(docker ps -q -f name=^/${CONTAINER_NAME}$)" ]; then
    echo "Container is already running. Entering..."
    docker exec -it $LOCALE_ENV $CONTAINER_NAME /bin/bash

elif [ "$(docker ps -aq -f name=^/${CONTAINER_NAME}$)" ]; then
    echo "Container exists but is stopped. Starting..."
    docker start $CONTAINER_NAME
    docker exec -it $LOCALE_ENV $CONTAINER_NAME /bin/bash

else
    echo "Creating a new container with volume mounting..."
    echo "Mounting $PROJECT_ROOT to /home/devuser/workspace"
    
    docker run -it \
        --name $CONTAINER_NAME \
        --shm-size=8g \
        $LOCALE_ENV \
        -v $VITIS_HOST_PATH:/home/tools/Vitis_2023.2 \
        -v $PROJECT_ROOT:/home/devuser/workspace \
        $IMAGE_NAME /bin/bash
fi