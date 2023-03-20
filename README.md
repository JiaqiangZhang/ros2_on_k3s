# ros2_on_k3s

`yolov5_ros2` package is based on [yolov5_ros2](https://github.com/fishros/yolov5_ros2)

`config` stores the `yolov5` model and camera info. After building `yolov5_ros2`, copy `config` to `install/yolov5_ros2/share/yolov5_ros2/config`

```bash
docker build -f ros2_yolov5.dockerfile -t yolov5_ros2:galactic-k3s .
```

## K3s config private registry
Add `mirrors` to `/etc/rancher/k3s/registries.yaml` (If not exist then create the file)

```yaml
mirrors:
  192.168.193.113:5000:
    endpoint:
      - "http://192.168.193.113:5000"
```

Restart
```
sudo systemctl restart k3s #master
sudo systemctl restart k3s-agent #agent
```

## Use a docker registry
- modify `/etc/docker/daemon.json`
Add following content to `daemon.json`
```
{
    "insecure-registries": ["ip_address:5000"]
}
```

- restart docker
```
systemctl daemon-reload && systemctl restart docker
```

May need to add `registry-mirrors` to `daemon.json` as well
```
{
    "registry-mirrors": [
        "https://hub-mirror.c.163.com",
        "https://mirror.baidubce.com"
    ],
    "insecure-registries": ["ip_address:5000"]
}

```

## Build a docker registry with ui
### Build registry
- pull and run registry on the server
```
docker pull registry:latest
docker run -d -p 5000:5000 --restart=always --name registry registry
```

- modify `/etc/docker/daemon.json`
Add following content to `daemon.json`
```
{
    "insecure-registries": ["ip_address:5000"]
}
```

- restart docker
```
systemctl daemon-reload && systemctl restart docker
```

### Docker registry UI
- pull the image of `docker-registry-ui`
```
docker pull joxit/docker-registry-ui:1.5-static
```

- deploy UI

```
docker run -p 8280:80 --name registry-ui \
-e REGISTRY_URL="http://ip_address:5000" \
-e DELETE_IMAGES="true" \
-e REGISTRY_TITLE="TIERS registry" \
-d joxit/docker-registry-ui:1.5-static

# docker run -p 8280:80 --name registry-ui -e REGISTRY_URL="http://ip_address:5000" -e DELETE_IMAGES="true" -e REGISTRY_TITLE="TIERS registry"
```

### Manage docker image
- pull image or build image with dockerfile
- tag the image to registry
```
# docker tag IMAGE:TAG REGISTRY_HOST:REGISTRY_PORT/REPOSITORY:TAG
docker tag hello-world:latest ip_address:5000/hello-world:latest
```

 - push the image to registry
```
docker push ip_address:5000/hello-world:latest
```

- check images
```
curl ip_address:5000/v2/_catalog
# {"repositories":["hello-world"]}
```

- pull images from registry
```
docker pull ip_address:5000/hello-world:latest
```