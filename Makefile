CC = clang
CFLAGS = -Wall -O0 -g 
LFLAGS = -O0 -g
LIBS = -lgsl -lm
GRAPH = gnuplot
BROWSER = google-chrome
FILE = sol
DIR=/home/jharvard/projects/glider
#uncomment #8 and #30:32 for output to be opened effortlessly 
URL = https://github.com/AlexisPrel/Glider.git

all: l_VS_v l_VS_theta l_VS_y run graphs clean

l_VS_v: main.c glider-ode.o lVSv0.c
	${CC} $(LFLAGS) -o $@ $^ $(LIBS)

l_VS_theta: main.c glider-ode.o lVStheta0.c
	${CC} $(LFLAGS) -o $@ $^ $(LIBS)
	
l_VS_y: main.c glider-ode.o lVSy0.c
	${CC} $(LFLAGS) -o $@ $^ $(LIBS)

run:
	./l_VS_v > l_of_v
	./l_VS_theta > l_of_theta
	./l_VS_y > l_of_y

graphs:
	$(GRAPH) glider.gpl
	google-chrome ${DIR}/l_of_v.png
	google-chrome ${DIR}/l_of_theta.png
	google-chrome ${DIR}/l_of_y.png

git-first:
	touch README.md
	git init
	git add .
	git remote add origin ${URL}
	# Done initialization
	make git-update
	
git-update:
	# Please make sure you have updated README.md
	indent *.c
	git push -u origin master

clean: 
	rm -f *~
	rm -f *.o
	rm -f l_VS_*

veryclean: clean
	rm -f l_of_*
