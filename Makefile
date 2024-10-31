# 컴파일러와 플래그 설정
CXX = g++
CXXFLAGS = -std=c++14 -Wall -O3

# 타겟 바이너리 이름
TARGET = user_management

# 소스 파일과 객체 파일 목록
SRC = main.cpp user.cpp storage.cpp
OBJ = $(SRC:.cpp=.o)

# 기본 빌드 규칙
all: $(TARGET)

# 타겟 빌드 규칙
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

# 객체 파일 빌드 규칙
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 청소 규칙
clean:
	rm -f $(OBJ) $(TARGET)