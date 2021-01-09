FROM ubuntu:latest

RUN apt-get update -y \
  && apt-get install -y --no-install-recommends build-essential \
  && apt-get -y install flex \
  && apt-get -y install bison \
  && apt-get -y install sudo \
  && rm -rf /var/lib/apt/lists/*

COPY . /usr/app/

VOLUME /usr/app
WORKDIR /usr/app

RUN chmod +x /usr/app/run.sh
CMD /bin/bash -c "sh ./run.sh"