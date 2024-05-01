#include <errno.h>
#include <fcntl.h>
#include <linux/rfkill.h>
#include <sys/ioctl.h>
#include <unistd.h>

int main() {
  int fd = open("/dev/rfkill", O_RDONLY);
  if (fd < 0)
    return errno;

  int r = ioctl(fd, RFKILL_IOCTL_NOINPUT);
  if (r < 0)
    return r;

  pause();

  return 0;
}
