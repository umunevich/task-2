import plots
import reader


root_path = 'D:/Learning/University2/Programming'


def main():
    points = reader.read(f'{root_path}/task-2/cmake-build-debug/result.csv')
    plots.build_plot(points, "points1", ("Threads", "Time"))


if __name__ == "__main__":
    main()
