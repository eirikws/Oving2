from threading import Thread, Lock

i = 0
lock=Lock()
def adder():
    global i
    for x in range(0, 1000000):
        lock.acquire()
        i += 1
        lock.release()

def decr():
    global i
    for x in range(0, 1000000):
        lock.acquire()
        i-=1
        lock.release()

def main():
    adder_thr = Thread(target = adder)
    decr_thr = Thread(target = decr)
    adder_thr.start()
    decr_thr.start()
    for x in range(10000):
        print(i)
    adder_thr.join()
    decr_thr.join()
    print("Done: " + str(i))


main()
