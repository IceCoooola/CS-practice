
class Subscriber:
    def __init__(self):
        self.cars = []
        self.user = {}
        self.user_carMove_idx = {}

    def add_car(self, x, y):
        car = Car(x, y)
        self.cars.append(car)

    def add_user(self, user, car_idx):
        self.user[user] = car_idx
        self.user_carMove_idx[user] = len(self.cars[car_idx].move_x)

class Car:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.move_x = []
        self.move_y = []

    def move(self, delta_x, delta_y):
        self.move_x.append(delta_x)
        self.move_y.append(delta_y)
        self.x += delta_x
        self.y += delta_y

    def getPos(self):
        return [self.x, self.y]




def main():
    # get the number of truck
    n = int(input("enter number of cars:\n"))
    line = input("enter pos of " + str(n) +" cars")
    coordinate = line.split(' ')
    sb = Subscriber()
    for i in range(n):
        sb.add_car(float(coordinate[i*2]), float(coordinate[i*2 + 1]))
    line = input("enter command:")
    while line != "":
        command = line.split(" ")
        if command[0] == 'S':
            sb.add_user(int(command[1]), int(command[2]))
            pos = sb.cars[int(command[2])].getPos()
            print("S ", command[1], pos[0], pos[1])
        elif command[0] == 'U':
            sb.cars[int(command[1])].move(float(command[2]), float(command[3]))
        elif command[0] == 'R':
            user = int(command[1])
            car_idx = sb.user[user]
            move_x = sb.cars[car_idx].move_x
            move_y = sb.cars[car_idx].move_y
            idx = sb.user_carMove_idx[int(command[1])]
            while idx < len(move_x):
                print('U', command[1], move_x[idx], move_y[idx])
                idx += 1



        line = input("enter command:")

if __name__ == "__main__":
    main()
