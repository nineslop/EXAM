FROM ubuntu:18.04

LABEL author="Ivanov Vladislav 221-352"

ENV TZ=Europe/Moscow  
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone  
RUN apt-get update  
RUN apt-get install qt5-default -y  
RUN apt-get install qtbase5-dev -y
RUN apt-get install qt5-qmake  
RUN apt-get install build-essential -y 

WORKDIR /root/
RUN mkdir Ivanov
WORKDIR /root/Ivanov/

COPY *.cpp /root/Ivanov/
COPY *.h /root/Ivanov/
COPY *.pro /root/Ivanov/

RUN qmake -o hallServer echoServer.pro 
RUN make hallServer

EXPOSE 33333