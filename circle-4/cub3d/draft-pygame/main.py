import pygame
import math
import sys

WINDOW = None
MAP_SIZE = 8
TILE_SIZE = 60
DATAMAP = [
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 0, 1, 0, 0, 0, 0, 1,
	1, 0, 1, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 1, 1, 1,
	1, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 1, 0, 0, 1,
	1, 0, 0, 0, 1, 0, 0, 1,
	1, 1, 1, 1, 1, 1, 1, 1
]
FOV = math.pi / 3

class Player:
	def __init__(self):
		self.x = TILE_SIZE * MAP_SIZE / 2
		self.y = TILE_SIZE * MAP_SIZE / 2
		self.direction = math.pi

def draw_player(player):
	pygame.draw.circle(WINDOW, (255, 0, 0), (player.x, player.y), 8)
	pygame.draw.line(WINDOW, (0, 255, 0), (player.x, player.y), (player.x - math.sin(player.direction - FOV / 2) * 50, player.y + math.cos(player.direction - FOV / 2) * 50), 3)
	pygame.draw.line(WINDOW, (0, 255, 0), (player.x, player.y), (player.x - math.sin(player.direction) * 50, player.y + math.cos(player.direction) * 50), 3)
	pygame.draw.line(WINDOW, (0, 255, 0), (player.x, player.y), (player.x - math.sin(player.direction + FOV / 2) * 50, player.y + math.cos(player.direction + FOV / 2) * 50), 3)


def draw_map():
	for i in range(len(DATAMAP)):
		x = i % MAP_SIZE
		y = math.floor(i / MAP_SIZE)
		tile = DATAMAP[i]
		color = (200, 200, 200) if tile == 1 else (100, 100, 100)
		pygame.draw.rect(WINDOW, color, (x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE - 2, TILE_SIZE - 2))

def setup_pygame():
	global WINDOW
	pygame.init()
	WINDOW = pygame.display.set_mode((TILE_SIZE * MAP_SIZE * 2, TILE_SIZE * MAP_SIZE))
	pygame.display.set_caption("cub3d draft")

def cast_rays(player):
	start = player.direction - FOV / 2
	casted_rays = int(TILE_SIZE * MAP_SIZE / 2)
	scale = TILE_SIZE * MAP_SIZE / (casted_rays)
	for ray in range(casted_rays):
		for depth in range(TILE_SIZE * MAP_SIZE):
			target_x = (player.x - math.sin(start) * depth)
			target_y = (player.y + math.cos(start) * depth)
			x = int(target_x / TILE_SIZE)
			y = int(target_y / TILE_SIZE)
			tile = y * MAP_SIZE + x
			if DATAMAP[tile] == 1:
				pygame.draw.rect(WINDOW, (0, 255, 0), (x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE - 2, TILE_SIZE - 2))
				depth *= math.cos(player.direction - start)
				wall_height = 21000 / (depth + 0.00001)
				c = 255 / (1 + depth * depth * 0.00001)
				pygame.draw.rect(WINDOW, (c, c, c), (TILE_SIZE * MAP_SIZE + ray * scale, TILE_SIZE * MAP_SIZE / 2 - wall_height / 2, scale + 1, wall_height))
				break
		pygame.draw.line(WINDOW, (255, 255, 0), (player.x, player.y), (target_x, target_y), 1)
		start += FOV / (casted_rays - 1)

def game_loop():
	player = Player()
	while True: # main game loop
		pygame.draw.rect(WINDOW, (255, 255, 255), (0, 0, TILE_SIZE * MAP_SIZE, TILE_SIZE * MAP_SIZE))
		pygame.draw.rect(WINDOW, (200, 200, 200), (TILE_SIZE * MAP_SIZE, 0, TILE_SIZE * MAP_SIZE, TILE_SIZE * MAP_SIZE / 2))
		pygame.draw.rect(WINDOW, (100, 100, 100), (TILE_SIZE * MAP_SIZE, TILE_SIZE * MAP_SIZE / 2, TILE_SIZE * MAP_SIZE, TILE_SIZE * MAP_SIZE / 2))
		for event in pygame.event.get():
			if event.type == pygame.QUIT:
				pygame.quit()
				sys.exit()
		keys = pygame.key.get_pressed()
		if keys[pygame.K_LEFT]:
			player.direction -= 0.1
		if keys[pygame.K_RIGHT]:
			player.direction += 0.1
		if keys[pygame.K_w]:
			new_x = int((player.x - math.sin(player.direction) * 3) / TILE_SIZE)
			new_y = int((player.y + math.cos(player.direction) * 3) / TILE_SIZE)
			if (DATAMAP[new_y * MAP_SIZE + new_x] == 0):
				player.x -= math.sin(player.direction) * 3
				player.y += math.cos(player.direction) * 3
		draw_map()
		cast_rays(player)
		draw_player(player)
		pygame.display.update()

def main():
	setup_pygame()
	game_loop()

if __name__ == '__main__':
	main()