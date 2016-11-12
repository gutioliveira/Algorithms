FROM ubuntu:14.04

RUN apt-get update

RUN apt-get -y install python3-pip

RUN apt-get -y install python3-pil

RUN python3 -m pip install FGAme

RUN apt-get -y install mercurial

RUN hg clone https://bitbucket.org/pygame/pygame

RUN apt-get update

RUN apt-get install -y python3-dev python3-numpy libsdl-image1.2-dev libsdl-mixer1.2-dev libsdl-ttf2.0-dev libsmpeg-dev libsdl1.2-dev libportmidi-dev libswscale-dev libavformat-dev libavcodec-dev libfreetype6-dev

RUN python3 pygame/setup.py build

RUN python3 pygame/setup.py install

RUN echo "hello2"

COPY . /

RUN export uid=1000 gid=1000 && \
    mkdir -p /home/developer && \
    echo "developer:x:${uid}:${gid}:Developer,,,:/home/developer:/bin/bash" >> /etc/passwd && \
    echo "developer:x:${uid}:" >> /etc/group && \
    echo "developer ALL=(ALL) NOPASSWD: ALL" > /etc/sudoers.d/developer && \
    chmod 0440 /etc/sudoers.d/developer && \
    chown ${uid}:${gid} -R /home/developer

USER developer
ENV HOME /home/developer
ENV SDL_VIDEODRIVER x11
ENV PULSE_SERVER unix:/home/developer/socket

ADD . /code
WORKDIR /code

RUN echo $PWD

CMD python3
