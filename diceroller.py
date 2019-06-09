#/usr/bin/env python3

from random import randint
import re

def dice_roll(number, dicetype):
    total = 0
    for i in range(number):
        total = total + randint(1, dicetype)

    return total

def parse_input():
    roll = input("Roll your dice! ")
    m = re.match( "(\d+)d(\d+)", roll)

    # TODO check matching
    # print(m.group(1),m.group(2))

    return m.group(1), m.group(2)


try:
    while(1):
        num, dice = parse_input()
        print(dice_roll(int(num), int(dice)))
except KeyboardInterrupt:
    pass


