//
// Design a template for children class use
//
typedef struct LED class_LED;

struct LED
{
	int gpio;

	int on;

	void (*Blink)(class_LED *);

};

void Blink(class_LED * led)
{
	if(led -> on == 1)
	{
		// Blink control
	}
}

void main(void)
{
	class_LED led1;

	led1.gpio = 1;

	led1.Blink = Blink;

	led1.Blink(&led1);
}