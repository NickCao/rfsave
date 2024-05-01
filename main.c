#include <fcntl.h>
#include <linux/rfkill.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>

int main() {
  int fd = open("/dev/rfkill", O_RDONLY);
  if (fd < 0) {
    perror("failed to open /dev/rfkill");
    exit(EXIT_FAILURE);
  }

  int r = ioctl(fd, RFKILL_IOCTL_NOINPUT);
  if (r < 0) {
    perror("failed to execute ioctl");
    exit(EXIT_FAILURE);
  }

  pause();

  exit(EXIT_SUCCESS);
}
