

#define UP 0
#define UP_LEFT 1
#define UP_RIGHT 2
#define MIDDLE 3
#define DOWN_LEFT 4
#define DOWN_RIGHT 5
#define DOWN 6

#define HOUR_1 0
#define HOUR_2 1
#define MINUTE_1 2
#define MINUTE_2 3
#define DOTS 4

#define LEFT_PIXEL 0
#define RIGHT_PIXEL 1

void light_digit_segment(int digit_number, int segment);
void begin();
void show();
void clear();
void light_digit(int pos, int number);

void led_time(int hour, int minute)
{
    if (hour > 9)
    {
        light_digit(HOUR_2, hour / 10);
        light_digit(HOUR_1, hour % 10);
    }
    else
    {
        light_digit(HOUR_2, 0);
        light_digit(HOUR_1, hour);
    }
    if (minute > 9)
    {
        light_digit(MINUTE_2, minute / 10);
        light_digit(MINUTE_1, minute % 10);
    }
    else
    {
        light_digit(MINUTE_2, 0);
        light_digit(MINUTE_1, minute);
    }
}

void scan()
{
    for (int i = 0; i < 57; i++)
    {
        pixels_left.clear();
        pixels_left.setPixelColor(i, pixels_left.Color(0, 255, 0));
        pixels_left.show();
        vTaskDelay(10);
    }
    for (int i = 0; i < 59; i++)
    {
        pixels_right.clear();
        pixels_right.setPixelColor(i, pixels_left.Color(0, 255, 0));
        pixels_right.show();
        vTaskDelay(10);
    }
}

void blink(bool state)
{
    if (state)
    {
        pixels_right.setPixelColor(0, pixels_right.Color(COLOR_R, COLOR_G, COLOR_B));
        pixels_right.setPixelColor(1, pixels_right.Color(COLOR_R, COLOR_G, COLOR_B));
    }
    else
    {
        pixels_right.setPixelColor(0, pixels_right.Color(0, 0, 0));
        pixels_right.setPixelColor(1, pixels_right.Color(0, 0, 0));
    }

}

void light_digit(int pos, int number)
{
    switch (number)
    {
    case 0:
        light_digit_segment(pos, UP);
        light_digit_segment(pos, UP_RIGHT);
        light_digit_segment(pos, UP_LEFT);
        light_digit_segment(pos, DOWN_RIGHT);
        light_digit_segment(pos, DOWN_LEFT);
        light_digit_segment(pos, DOWN);
        break;
    case 1:
        light_digit_segment(pos, UP_RIGHT);
        light_digit_segment(pos, DOWN_RIGHT);
        break;
    case 2:
        light_digit_segment(pos, UP);
        light_digit_segment(pos, UP_RIGHT);
        light_digit_segment(pos, MIDDLE);
        light_digit_segment(pos, DOWN_LEFT);
        light_digit_segment(pos, DOWN);
        break;
    case 3:
        light_digit_segment(pos, UP);
        light_digit_segment(pos, UP_RIGHT);
        light_digit_segment(pos, MIDDLE);
        light_digit_segment(pos, DOWN_RIGHT);
        light_digit_segment(pos, DOWN);
        break;
    case 4:
        light_digit_segment(pos, UP_LEFT);
        light_digit_segment(pos, UP_RIGHT);
        light_digit_segment(pos, MIDDLE);
        light_digit_segment(pos, DOWN_RIGHT);
        break;
    case 5:
        light_digit_segment(pos, UP);
        light_digit_segment(pos, UP_LEFT);
        light_digit_segment(pos, MIDDLE);
        light_digit_segment(pos, DOWN_RIGHT);
        light_digit_segment(pos, DOWN);
        break;
    case 6:
        light_digit_segment(pos, UP);
        light_digit_segment(pos, UP_LEFT);
        light_digit_segment(pos, MIDDLE);
        light_digit_segment(pos, DOWN_RIGHT);
        light_digit_segment(pos, DOWN_LEFT);
        light_digit_segment(pos, DOWN);
        break;
    case 7:
        light_digit_segment(pos, UP);
        light_digit_segment(pos, UP_RIGHT);
        light_digit_segment(pos, DOWN_RIGHT);
        break;
    case 8:
        light_digit_segment(pos, UP);
        light_digit_segment(pos, UP_RIGHT);
        light_digit_segment(pos, UP_LEFT);
        light_digit_segment(pos, MIDDLE);
        light_digit_segment(pos, DOWN_RIGHT);
        light_digit_segment(pos, DOWN_LEFT);
        light_digit_segment(pos, DOWN);
        break;
    case 9:
        light_digit_segment(pos, UP);
        light_digit_segment(pos, UP_RIGHT);
        light_digit_segment(pos, UP_LEFT);
        light_digit_segment(pos, MIDDLE);
        light_digit_segment(pos, DOWN_RIGHT);
        light_digit_segment(pos, DOWN);
        break;
    }
}

void light_segment(int pos, int first_led)
{

    switch (pos)
    {
    case LEFT_PIXEL:
        for (int i = first_led; i < first_led + 4; i++)
        {
            pixels_left.setPixelColor(i, pixels_left.Color(COLOR_R, COLOR_G, COLOR_B));
        }
        break;
    case RIGHT_PIXEL:
        for (int i = first_led; i < first_led + 4; i++)
        {
            pixels_right.setPixelColor(i, pixels_right.Color(COLOR_R, COLOR_G, COLOR_B));
        }
        break;
    }
}

void light_digit_segment(int digit_number, int segment)
{
    switch (digit_number)
    {
    case MINUTE_2:
        switch (segment)
        {
        case DOWN:
            light_segment(LEFT_PIXEL, 20);
            break;
        case DOWN_RIGHT:
            light_segment(LEFT_PIXEL, 24);
            break;
        case DOWN_LEFT:
            light_segment(LEFT_PIXEL, 16);
            break;
        case MIDDLE:
            light_segment(LEFT_PIXEL, 12);
            break;
        case UP_RIGHT:
            light_segment(LEFT_PIXEL, 8);
            break;
        case UP_LEFT:
            light_segment(LEFT_PIXEL, 0);

            break;
        case UP:
            light_segment(LEFT_PIXEL, 4);
            break;
        }
        break;
    case MINUTE_1:
        switch (segment)
        {
        case DOWN:
            light_segment(LEFT_PIXEL, 32);
            break;
        case DOWN_LEFT:
            light_segment(LEFT_PIXEL, 28);
            break;
        case DOWN_RIGHT:
            light_segment(LEFT_PIXEL, 36);
            break;
        case MIDDLE:
            light_segment(LEFT_PIXEL, 40);
            break;
        case UP_RIGHT:
            light_segment(LEFT_PIXEL, 52);
            break;
        case UP_LEFT:
            light_segment(LEFT_PIXEL, 44);
            break;
        case UP:
            light_segment(LEFT_PIXEL, 48);
            break;
        }
        break;
    case HOUR_2:
        switch (segment)
        {
        case DOWN:
            light_segment(RIGHT_PIXEL, 50);
            break;
        case DOWN_LEFT:
            light_segment(RIGHT_PIXEL, 54);
            break;
        case DOWN_RIGHT:
            light_segment(RIGHT_PIXEL, 46);
            break;
        case MIDDLE:
            light_segment(RIGHT_PIXEL, 42);
            break;
        case UP_RIGHT:
            light_segment(RIGHT_PIXEL, 30);
            break;
        case UP_LEFT:
            light_segment(RIGHT_PIXEL, 38);
            break;
        case UP:
            light_segment(RIGHT_PIXEL, 34);
            break;
        }
        break;

    case HOUR_1:
        switch (segment)
        {
        case DOWN:
            light_segment(RIGHT_PIXEL, 22);
            break;
        case DOWN_LEFT:
            light_segment(RIGHT_PIXEL, 26);
            break;
        case DOWN_RIGHT:
            light_segment(RIGHT_PIXEL, 18);
            break;
        case MIDDLE:
            light_segment(RIGHT_PIXEL, 14);
            break;
        case UP_RIGHT:
            light_segment(RIGHT_PIXEL, 2);
            break;
        case UP_LEFT:

            light_segment(RIGHT_PIXEL, 10);
            break;
        case UP:
            light_segment(RIGHT_PIXEL, 6);
            break;
        }
        break;
    }
}

void test_segment(int pos, int time)
{
    for (int i = 0; i < 7; i++)
    {
        light_digit_segment(pos, i);
        show();
        delay(time);
        clear();
    }
}

void test_digit(int pos, int time)
{
    for (int i = 0; i <= 9; i++)
    {
        Serial.println(i);
        light_digit(pos, i);
        show();
        delay(time);
        clear();
    }
}

void test_all_digits()
{
    test_digit(HOUR_1, 100);
    test_digit(HOUR_2, 100);
    test_digit(MINUTE_1, 100);
    test_digit(MINUTE_2, 100);
}

void begin()
{
    pixels_left.begin();
    pixels_right.begin();
}

void show()
{
    pixels_left.show();
    pixels_right.show();
}

void clear()
{
    pixels_left.clear();
    pixels_right.clear();
}
