TARGET = outliers

KMEANS = kmeans.c distances.c
STANDARDSCALE = standardscale.c zscores.c
.PHONY: all $(TARGET) clean

all: $(TARGET)

$TARGET:
	gcc $(KMEANS) $(STANDARDSCALE) -o $(TARGET)

clean:
	rm -f $(TARGET)
