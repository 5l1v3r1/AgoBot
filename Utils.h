#ifndef UTILS_H
#define UTILS_H

#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <signal.h>
#include <syslog.h>
#include <sys/time.h>
#include <unistd.h>
#include <time.h>

#ifndef M_PI
#define M_PI       3.14159265358979323846
#endif

typedef struct Vec2
{
	int x;
	int y;
} Vec2;

typedef struct Vec2f
{
	double x;
	double y;
} Vec2f;

typedef enum NODE_TYPE
{
	FOOD,
	VIRUS,
	PLAYER
} NODE_TYPE;

typedef enum ZONE
{
	LEFT_UP,
	LEFT_DOWN,
	RIGHT_UP,
	RIGHT_DOWN
} ZONE;

typedef enum SIDE
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	NOTHING
} SIDE;

typedef struct Node
{
	unsigned int nodeID;
	unsigned int x;
	unsigned int y;
	unsigned short size;
	unsigned char flags;
	unsigned char R,G,B;
	NODE_TYPE type;
	unsigned char* name;
	unsigned char isSafe;
} Node;

typedef struct NodeStack
{
	Node* node;
	struct NodeStack* next;
} NodeStack;

void NodeStack_push(NodeStack** list, Node* elem);
void NodeStack_clear(NodeStack* list);
Node* NodeStack_get(NodeStack* list, unsigned int id);
NodeStack* NodeStack_remove(NodeStack* list, unsigned int id);
char NodeStack_find(NodeStack* list, unsigned int id);
size_t NodeStack_length(NodeStack* list);
void NodeStack_update(NodeStack** list, Node* elem);
Node* NodeStack_getLowest(NodeStack* list);
Node* NodeStack_getLargest(NodeStack* list);
Node* NodeStack_getNearest(NodeStack* list, Node* node);

double getDistance(Node* n1, Node* n2);
double getDist(Vec2 a, Vec2 b);
double getDistf(Vec2f a, Vec2f b);
unsigned int getFoodNum(NodeStack* list);

ZONE getZone(Node* p);
Vec2 gotoZone(ZONE zone);
ZONE getOppositeZone();

Vec2f Vec2_normalize(Vec2 vec);
Vec2f Vec2f_normalize(Vec2f vec);
double Vec2_length(Vec2 vec);
Vec2f Vec2toVec2f(Vec2 vec);
Vec2 Vec2ftoVec2(Vec2f vec);
Vec2 NodetoVec2(Node* node);
double Vec2_scalar(Vec2 vec1, Vec2 vec2);

Vec2 rotateVec2(Vec2 vec, int angle);
int getAngleVirus(Node* virus, Node* player);
int getAngleThreat(Node* threat, Node* player);
double getWallDistance(Node* node);
Vec2 getWallForce(Node* node);
double getAngle(Vec2 vec1, Vec2 vec2);

int getMass(Node* node);

double splitDistance(Node* node);

void printHex(char* data, size_t size);
             
double max(double a, double b);
double min(double a, double b);

#endif