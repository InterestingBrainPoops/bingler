CC = gcc

ODIR = obj
SRCDIR = src

IDIR = include

_OBJ = main.o 
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))



$(ODIR)/%.o : $(SRCDIR)/%.c | $(ODIR)
	$(CC) -g -c -o $@ $^ -I $(IDIR)/ $(CFLAGS)

bingler: $(OBJ) 
	$(CC) -o $@ $^ $(CFLAGS)


$(ODIR):
	mkdir -p $@


debug: $(OBJ) 
	$(CC) -g -o gran_d -O0 $^ $(CFLAGS)

.PHONY : run 
run: $(OBJ) 
	$(CC) -o $@ $^ $(CFLAGS) && ./gran

.PHONY : clean 
clean: 
	rm -f $(ODIR)/*.o