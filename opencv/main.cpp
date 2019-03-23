#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <numeric>
using namespace cv;
using namespace std;
int main(int argc, char** argv)
{
	signed char t = 0xff;
	unsigned char z = 0xff;

	if (argc != 2)
	{
		cout << " Usage: display_image ImageToLoadAndDisplay" << endl;
		return -1;
	}
	Mat image;
	image = imread(argv[1], IMREAD_COLOR); // Read the file
	if (image.empty()) // Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}
	namedWindow("Display window", WINDOW_AUTOSIZE); // Create a window for display.
	imshow("Display window", image); // Show our image inside it.
	waitKey(0); // Wait for a keystroke in the window


	vector<int> s; //empty can't use s[] without initialize
	for (const char& op : "12+")
	{
		if (op == '+')
			s.push_back(s.end()[-1] + s.end()[-2]);
		else
			s.push_back(int(op));
	}
	int sum = accumulate(s.begin(), s.end(), 0);

	return 0;
}