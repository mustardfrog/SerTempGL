SRCS=src/Main.cpp src/glad.c src/Core/GL.cpp src/Engine.cpp
INCLUDE=-Ivendor/glad/include -Ivendor/glm
OPTS=-lGL -lglfw -ldl  -lX11 -lXrandr -lpthread

opengl: $(SRCS)
	@g++ $(SRCS) $(INCLUDE) $(OPTS) -o opengl
	@./opengl
