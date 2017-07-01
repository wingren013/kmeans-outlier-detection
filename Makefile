TARGET = outliers

KMEANS = kmeans.c distances.c
STANDARDSCALE = standardscale.c zscores.c
.PHONY: all clean

all: $(TARGET)

$(TARGET):
	gcc $(KMEANS) $(STANDARDSCALE) main.c -o $(TARGET)

clean:
	rm -f $(TARGET)
