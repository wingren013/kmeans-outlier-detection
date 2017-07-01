TARGET: outliers

KMEANS: kmeans.c distances.c
STANDARDSCALE: standardscale.c zscores.c
.phony all $TARGET clean

all: clean $TARGET

$TARGET:
	gcc $KMEANS $STANDARDSCALE -o $TARGET

clean:
	rm -f $TARGET