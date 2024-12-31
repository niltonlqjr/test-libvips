all: invert stats crop

invert:
	gcc invert.c `pkg-config vips --libs --cflags` -o invert

stats:
	gcc stats.c `pkg-config vips --libs --cflags` -o stats

crop:
	gcc crop.c `pkg-config vips --libs --cflags` -o crop

clean:
	rm -f stats invert crop
