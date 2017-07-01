TARGET = outliers

KMEANS = kmeans.c distances.c
STANDARDSCALE = standardscale.c zscores.c
.PHONY: all clean

all: $(TARGET)

$(TARGET):
	gcc $(KMEANS) $(STANDARDSCALE) main.c -o $(TARGET)

debug: clean
	gcc $(KMEANS) $(STANDARDSCALE) main.c -o $(TARGET) -fsanitize=address

clean:
	rm -f $(TARGET)
re: clean $(TARGET)
