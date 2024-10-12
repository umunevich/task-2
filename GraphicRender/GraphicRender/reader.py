import csv


def parse_row(row, res):
    if row:
        thread_time = list(map(int, row))
        res.update({thread_time[0]: thread_time[1]})
        return thread_time


def read(path: str) -> dict[int, int]:
    try:
        with open(path, 'r') as file:
            res = dict()
            lines = file.readlines()[1:]
            reader = csv.reader(lines)
            for row in reader:
                parse_row(row, res)
        return res
    except Exception as e:
        print(e)


if __name__ == '__main__':
    data = read('D:/Learning/University2/Programming/task-2/cmake-build-debug/result.csv')
    print(data)
