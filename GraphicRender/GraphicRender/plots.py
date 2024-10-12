import matplotlib.pyplot as plt


FIG_SIZE = (10, 10)
LABELS_SIZE = 18
TICKS_SIZE = 14


def styling(image_name: str, labels: tuple[str, str]):
    plt.xticks(fontsize=TICKS_SIZE)
    plt.yticks(fontsize=TICKS_SIZE)
    plt.title(image_name, fontsize=LABELS_SIZE)
    plt.xlabel(labels[0], fontsize=LABELS_SIZE)
    plt.ylabel(labels[1], fontsize=LABELS_SIZE)


def build_plot(points: dict[int, int], image_name: str, labels: tuple[str, str]):
    plt.figure(figsize=FIG_SIZE)
    plt.scatter(list(points.keys()), list(points.values()), marker="o")
    styling(image_name, labels)

    print(f"saving {image_name}...")
    plt.savefig(f"{image_name}.png")
    print(f"{image_name} saved")


if __name__ == "__main__":
    build_plot({1: 2}, "pipi", ("Threads", "Time in ns"))
