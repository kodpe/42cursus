#!/bin/bash
docker system prune -a -f
docker volume prune -f
docker volume rm -f postgres_data
docker ps -a && docker volume ls

