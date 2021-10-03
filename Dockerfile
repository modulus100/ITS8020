FROM ubuntu:latest
RUN apt-get update && \
    apt-get install -y sudo curl git-core gnupg linuxbrew-wrapper locales nodejs zsh wget nano nodejs npm fonts-powerline && \
    locale-gen en_US.UTF-8 && \
    adduser --quiet --disabled-password --shell /bin/zsh --home /home/devuser --gecos "User" devuser && \
    echo "devuser:p@ssword1" | chpasswd &&  usermod -aG sudo devuser

ADD scripts/installthemes.sh /home/devuser/installthemes.sh
USER devuser
ENV TERM xterm
ENV ZSH_THEME agnoster
CMD ["zsh"]