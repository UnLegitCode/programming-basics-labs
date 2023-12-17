#include <stdio.h>
#include <minmax.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    double x;
    double y;
} Point;

void inputPoint(Point* point) {
    scanf("%lf %lf", &point->x, &point->y);
}

void outputPoint(const Point point) {
    printf("(%.3lf; %.3lf)\n", point.x, point.y);
}

void initPoints() {
    Point p1 = { 5, 10 };
    Point p2 = p1;

    p1 = p2;
}

void inputPoints(Point* array, const int size) {
    for (int i = 0; i < size; ++i) {
        inputPoint(array + i);
    }
}

void outputPoints(Point* array, const int size) {
    for (int i = 0; i < size; ++i) {
        outputPoint(array[i]);
    }
}

Point getMiddlePoint(const Point p1, const Point p2) {
    Point middlePoint = { max(p1.x, p2.x) - fabs(p1.x - p2.x), max(p1.y, p2.y) - fabs(p1.y - p2.y) };

    return middlePoint;
}

bool isEqualDouble(const double a, const double b) {
    return (a - b) < DBL_EPSILON;
}

bool isEqualPoint(const Point p1, const Point p2) {
    return isEqualDouble(p1.x, p2.x) && isEqualDouble(p1.y, p2.y);
}

bool isMiddlePoint(const Point p1, const Point p2, const Point p3) {
    return isEqualPoint(p3, getMiddlePoint(p1, p2));
}

void swapDouble(double* a, double* b) {
    const double temp = *a;

    *a = *b;
    *b = temp;
}

void swapCoordinates(Point* point) {
    swapDouble(&point->x, &point->y);
}

void swapPoints(Point* p1, Point* p2) {
    const Point temp = *p1;

    memmove(p1, p2, sizeof(Point));
    memmove(p2, &temp, sizeof(Point));
}

double getDistance(const Point p1, const Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int compareDouble(const double a, const double b) {
    if (a > b) {
        return 1;
    }

    return (a < b) ? -1 : 0;
}

int comparePoints(const void* one, const void* two) {
    const Point p1 = *((const Point*) one);
    const Point p2 = *((const Point*) two);

    if (isEqualDouble(p1.x, p2.x)) {
        return compareDouble(p1.y, p2.y);
    }

    return compareDouble(p1.x, p2.x);
}

int comparePointsByDistance(const void* one, const void* two) {
    static const Point NULL_POINT = { 0, 0 };

    return compareDouble(
            getDistance(NULL_POINT, *((const Point*) one)),
            getDistance(NULL_POINT, *((const Point*) two))
    );
}

typedef struct {
    double a;
    double b;
    double c;
} Line;

void inputLine(Line* line) {
    scanf("%lf %lf %lf", &line->a, &line->b, &line->c);
}

void initLine() {
    Line line = { 1, 2, 3 };
}

Line getLineByCoordinates(const double x1, const double y1, const double x2, const double y2) {
    return (Line) {
        y2 - y1,
        x2 - x1,
        (x2 * y1) - (x1 * y2)
    };
}

Line getLineByPoints(const Point p1, const Point p2) {
    return getLineByCoordinates(p1.x, p1.y, p2.x, p2.y);
}

void outputLineEquation(const Line Line) {
    printf("%+.2lfx%+.2lfy%+.2lf = 0\n", Line.a, Line.b, Line.c);
}

bool isParallel(const Line l1, const Line l2) {
    return (l1.a * l2.b) == (l1.b * l2.a);
}

bool isPerpendicular(const Line l1, const Line l2) {
    return (l1.a * l2.b) == -(l1.b * l2.a);
}

bool hasParallelLines(const Line* lines, const int size) {
    for (int i = 0; i < (size - 1); ++i) {
        Line line = lines[i];

        for (int j = i + 1; j < size; j++) {
            if (isParallel(line, lines[j])) {
                return true;
            }
        }
    }

    return false;
}

void printintersectionpoint(const Line l1, const Line l2) {
    double det = (l1.a * l2.b) - (l2.a * l1.b);

    if (det == 0) {
        printf("Lines do not intersect.\n");
    } else {
        printf(
                "Intersection Point: (%lf, %lf)\n",
                (l1.c * l2.b - l1.b * l2.c),
                (l1.a * l2.c - l1.c * l2.a)
        );
    }
}

typedef struct {
    Point center;
    double radius;
} Circle;

void initCircle() {
    Circle circle = {
            { 1, 2 },
            1
    };

    Circle circles[] = {
            {

                { 3, 4 },
                2
            },
            {
                    { 5, 6 },
                    3
            }
    };
}

void inputCircle(Circle* circle) {
    inputPoint(&circle->center);
    scanf("%lf", &circle->radius);
}

void inputCircles(Circle* circles, const int size) {
    for (int i = 0; i < size; ++i) {
        inputCircle(circles + i);
    }
}

void outputCircle(Circle circle) {
    printf("(%.2lf; %.2lf) - %.2lf\n", circle.center.x, circle.center.y, circle.radius);
}

void outputCircles(const Circle* circles, const int size) {
    for (int i = 0; i < size; ++i) {
        outputCircle(circles[i]);
    }
}

bool hasOneOuterIntersection(Circle c1, Circle c2) {
    return fabs(getDistance(c1.center, c2.center) - c1.radius - c2.radius) < DBL_EPSILON;
}

bool isInside(const Circle c1, const Circle c2) {
    const double distance = sqrt((c1.center.x - c2.center.x) * (c1.center.x - c2.center.x) + (c1.center.y - c2.center.y) * (c1.center.y - c2.center.y));

    return distance <= (c1.radius - c2.radius);
}

Circle findLargestCircle(const Circle* array, const int size) {
    int maxCount = 0,
        minRadius = 0,
        maxIndex = 0;

    for (int i = 0; i < size; i++) {
        int count = 0;

        for (int j = 0; j < size; j++) {
            if (i != j && isInside(array[j], array[i])) {
                count++;
            }
        }

        if ((count > maxCount) || (count == maxCount && array[i].radius < minRadius)) {
            maxCount = count;
            minRadius = array[i].radius;
            maxIndex = i;
        }
    }

    return array[maxIndex];
}

void swap(Circle* a, Circle* b) {
    const Circle temp = *a;

    *a = *b;
    *b = temp;
}

int countEnclosedCircles(Circle circle, const Circle* array, const int size) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        const double distance = pow(circle.center.x - array[i].center.x, 2) + pow(circle.center.y - array[i].center.y, 2);

        if (distance < ((circle.radius - array[i].radius) * (circle.radius - array[i].radius))) {
            count++;
        }
    }

    return count;
}

int compareCircles(const void* a, const void* b) {
    const Circle* circleA = (const Circle*) a;
    const Circle* circleB = (const Circle*) b;

    const int countA = countEnclosedCircles(*circleA, circleA, *((int*) b));
    const int countB = countEnclosedCircles(*circleB, circleB, *((int*) b));

    if (countA == countB) {
        return circleA->radius - circleB->radius;
    }

    return countA - countB;
}

typedef struct {
    int numerator;
    int denumerator;
} Fraction;

void inputFraction(Fraction* fraction) {
    scanf("%d/%d", &fraction->numerator, &fraction->denumerator);
}

void inputFractions(Fraction* fractions, const int size) {
    for (int i = 0; i < size; ++i) {
        inputFraction(fractions + i);
    }
}

void outputFraction(const Fraction* fraction) {
    printf("%d/%d", fraction->numerator, fraction->denumerator);
}

void outputFractions(const Fraction* fraction, const int size) {
    for (int i = 0; i < size; ++i) {
        outputFraction(fraction + i);
    }
}

int gcd(const int a, const int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

int lcm(const int a, const int b) {
    return (a * b) / gcd(a, b);
}

void simpleFraction(Fraction* fraction) {
    const int fractionGcd = gcd(fraction->numerator, fraction->denumerator);

    fraction->numerator /= fractionGcd;
    fraction->denumerator /= fractionGcd;
}

Fraction multiplyFractions(const Fraction first, const Fraction second) {
    const int numerator = first.numerator * second.numerator;
    const int denumerator = first.denumerator * second.denumerator;
    const int fractionGcd = gcd(numerator, denumerator);

    return (Fraction) {
            numerator / fractionGcd,
            denumerator / fractionGcd
    };
}

Fraction divideFractions(const Fraction first, const Fraction second) {
    const int numerator = first.numerator * second.denumerator;
    const int denumerator = first.denumerator * second.numerator;
    const int fractionGcd = gcd(numerator, denumerator);

    return (Fraction) {
        numerator / fractionGcd,
        denumerator / fractionGcd
    };
}

Fraction addFractions(const Fraction first, const Fraction second) {
    const int denumerator = lcm(first.denumerator, second.denumerator);
    const int numerator = first.numerator * denumerator / first.denumerator + second.numerator * denumerator / second.denumerator;
    const int fractionGcd = gcd(numerator, denumerator);

    return (Fraction) {
            numerator / fractionGcd,
            denumerator / fractionGcd
    };
}

Fraction subtractFractions(const Fraction first, const Fraction second) {
    const int denumerator = lcm(first.denumerator, second.denumerator);
    const int numerator = first.numerator * denumerator / first.denumerator - second.numerator * denumerator / second.denumerator;
    const int fractionGcd = gcd(numerator, denumerator);

    return (Fraction) {
        numerator / fractionGcd,
        denumerator / fractionGcd
    };
}

Fraction sumFractions(const Fraction* fractions, const int size) {
    int numerator = 0,
        denumerator = 1;

    for (int i = 0; i < size; ++i) {
        const Fraction fraction = fractions[i];

        numerator = (numerator * fraction.denumerator) + (fraction.numerator * denumerator);
        denumerator *= fraction.denumerator;
    }

    const int fractionGcd = gcd(numerator, denumerator);

    return (Fraction) {
        numerator / fractionGcd,
        denumerator / fractionGcd
    };
}

#define MARK_AMOUNT 5

typedef struct {
    char surname[20];
    int marks[MARK_AMOUNT];
} Student;

bool isStudentBad(const Student student) {
    bool notGood = false;

    for (int i = 0; i < MARK_AMOUNT; ++i) {
        if (student.marks[i] == 2) {
            if (notGood) {
                return true;
            }

            notGood = true;
        }
    }

    return false;
}

int removeBadStudents(Student* students, const int size) {
    int newSize = 0;

    for (int i = 0; i < size; i++) {
        const Student student = students[i];

        if (isStudentBad(student)) {
            students[newSize++] = student;
        }
    }

    return newSize;
}

#define MINUTES_IN_HOUR 60
#define SECONDS_IN_MINUTE 60

typedef struct {
    int hours;
    int minutes;
    int seconds;
} Timestamp;

int getSeconds(const Timestamp timestamp) {
    return (timestamp.hours * MINUTES_IN_HOUR + timestamp.minutes) * SECONDS_IN_MINUTE + timestamp.seconds;
}

int compareInt(const int first, const int second) {
    if (first > second) {
        return 1;
    }

    return (first == second) ? 0 : -1;
}

int compareTimestamps(const Timestamp first, const Timestamp second) {
    return compareInt(getSeconds(first), getSeconds(second));
}

int timestampComparator(const void* first, const void* second) {
    return compareTimestamps(*((const Timestamp*) first), *((const Timestamp *) second));
}

Timestamp timestampFromSeconds(const int seconds) {
    const int minutes = seconds / SECONDS_IN_MINUTE;
    const int hours = minutes / MINUTES_IN_HOUR;

    return (Timestamp) {
        hours,
        minutes % (hours * MINUTES_IN_HOUR),
        seconds % (minutes * SECONDS_IN_MINUTE)
    };
}

Timestamp getDelay(const Timestamp from, const Timestamp to) {
    return timestampFromSeconds(getSeconds(from) - getSeconds(to));
}