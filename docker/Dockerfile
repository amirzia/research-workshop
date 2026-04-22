FROM ubuntu:22.04

RUN apt-get update && apt-get install -y g++

WORKDIR /app
COPY main.cpp .
COPY sample.txt .

RUN g++ -O2 -std=c++17 -o wordfreq main.cpp

CMD ["./wordfreq", "sample.txt", "10"]
