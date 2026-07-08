# Reproducible build environment for the Persona 3 FES decompilation.
#
# This image provides everything EXCEPT the two things you must supply yourself
# (they cannot be redistributed):
#   * the CodeWarrior PS2 toolchain (mwccps2.exe, mwldps2.exe)
#   * your legally-owned retail SLUS_216.21
#
# Build:  docker build -t p3fes .
# Run:    docker run --rm -it -v "$PWD:/work" -v "/path/to/cw:/opt/cw" p3fes
# Inside, point tools/verify_config.local.json (or P3_MWCC/P3_RETAIL_ELF) at the
# mounted toolchain + ELF; wibo runs the Windows .exe tools on Linux.
FROM debian:bookworm-slim

RUN dpkg --add-architecture i386 \
    && apt-get update \
    && apt-get install -y --no-install-recommends \
        binutils-mipsel-linux-gnu \
        python3 python3-pip python3-venv \
        clang-format make ca-certificates wget \
    && rm -rf /var/lib/apt/lists/*

# wibo runs the Windows CodeWarrior .exe tools under Linux.
RUN wget -q -O /usr/local/bin/wibo \
        https://github.com/decompals/wibo/releases/download/0.6.13/wibo \
    && chmod +x /usr/local/bin/wibo

COPY tools/requirements-python.txt /tmp/requirements-python.txt
RUN pip3 install --break-system-packages -r /tmp/requirements-python.txt

WORKDIR /work
CMD ["/bin/bash"]
