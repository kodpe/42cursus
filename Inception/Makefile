all:
	@mkdir -p  /home/sloquet/data/www_volume
	@mkdir -p  /home/sloquet/data/database_volume
	@chmod 755 /home/sloquet/data/www_volume
	@chmod 755 /home/sloquet/data/database_volume
	docker compose -f ./srcs/docker-compose.yml up -d --build

fclean:
	docker compose -f srcs/docker-compose.yml down
	docker system prune -af

logs:
	docker compose -f srcs/docker-compose.yml logs

status:
	docker ps -a
	@echo
	docker volume ls
	@echo
	ls /home/sloquet/data/www_volume
	@echo
	ls /home/sloquet/data/database_volume
	@echo
	docker network ls
	@echo
	curl -Ik http://sloquet.42.fr || true
	@echo
	curl -Iks https://sloquet.42.fr | head -1 || true
	@echo
	curl -Iks https://sloquet.42.fr/login | head -1 || true

.PHONY: all fclean logs status
