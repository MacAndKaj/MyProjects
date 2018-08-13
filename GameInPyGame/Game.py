import threading
import pygame
from pygame.locals import *

pygame.init()

screen = pygame.display.set_mode((1020, 780), RESIZABLE)
bgcolors = [0, 0, 0]
Done = False

for i in range(0, 255, 5):
    for ind in range(0, len(bgcolors)):
        bgcolors[ind] = i
    screen.fill(bgcolors)
    pygame.display.update()
    pygame.display.flip()


def handleKeys():
    global Done
    keys = pygame.key.get_pressed()
    if keys[pygame.K_ESCAPE]:
        Done = True


def handleEvents():
    global Done
    while not Done:
        for event in pygame.event.get():
            if event.type == QUIT:
                Done = True
        handleKeys()


def render():
    while not Done:
        pygame.display.update()
        pygame.display.flip()
    pygame.quit()


Render = threading.Thread(target=render, name='Game')
Handler = threading.Thread(target=handleEvents)

Render.start()
Handler.start()
