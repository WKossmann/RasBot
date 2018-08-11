from RasBot import RasBot
from time import sleep

robot = RasBot()

robot.moveF(80)
sleep(1)
robot.moveB(80)
sleep(1)
robot.turnL(50)
sleep(1)
robot.turnR(50)
sleep(1)
robot.stop()