#include "stdio.h"
#include "stdlib.h"

typedef struct orginal_t orginal_t;
typedef struct proxy_t proxy_t;

struct orginal_t
{
	int a;
	void (*Access)(orginal_t *, int);

};

struct proxy_t
{
	int access;

	orginal_t *obj;

	void (*Access)(proxy_t *, int);
};

void Orginal_Access(orginal_t *obj, int a)
{
	obj -> a = a;
}

void Proxy_Access(proxy_t *proxy, int a)
{
	if(proxy -> access)
	{
		Orginal_Access(proxy -> obj, a);
		printf("Vaule = %d\n", proxy -> obj -> a);
	}
	else
	{
		printf("Can not do this.\n");
	}
}

void main(void)
{
	orginal_t obj;
	proxy_t proxy;

	obj.Access = Orginal_Access;

	proxy.Access = Proxy_Access;
	proxy.obj = &obj;

	proxy.access = 0;

	proxy.Access(&proxy, 1);

	proxy.access = 1;

	proxy.Access(&proxy, 1);


}