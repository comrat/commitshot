#ifndef CAPTURE_H
#define CAPTURE_H

#include <stdio.h>
#include <stdint.h>

typedef struct {
	uint8_t* start;
	size_t length;
} buffer_t;

typedef struct {
	int fd;
	uint32_t width;
	uint32_t height;
	size_t buffer_count;
	buffer_t* buffers;
	buffer_t head;
} camera_t;

const char* CAM_DEV = "/dev/video0";
const int CAM_WIDTH = 352;
const int CAM_HEIGHT = 288;


camera_t* camera_open(const char* device);
uint8_t* yuyv2rgb(uint8_t* yuyv, uint32_t width, uint32_t height);
void quit(const char* msg);
void camera_init(camera_t* camera);
void camera_start(camera_t* camera);
void camera_stop(camera_t* camera);
void camera_finish(camera_t* camera);
void camera_close(camera_t* camera);
void jpeg(FILE* dest, uint8_t* rgb, uint32_t width, uint32_t height, int quality);
void capture_frame();
int xioctl(int fd, int request, void* arg);
int camera_capture(camera_t* camera);
int camera_frame(camera_t* camera, struct timeval timeout);
int minmax(int min, int v, int max);
int check_camera();

#endif
