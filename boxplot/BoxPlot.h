#include <vector>
#include <algorithm>
#include <cmath>

class BoxPlot {
public:
    static double min(const std::vector<double>& x) {
        return *(std::min_element(x.begin(), x.end()));
    }

    static double max(const std::vector<double>& x) {
        return *(std::max_element(x.begin(), x.end()));
    }

    static double median(std::vector<double> x) {
        size_t n = x.size();
        switch (n) {
        case 0:
            return 0;
        }
       
        std::sort(x.begin(), x.end());
        if (n % 2 == 0) {
            return (x[n / 2 - 1] + x[n / 2]) / 2;
        }
        else {
            return x[n / 2];
        }
    }

    static double mean(const std::vector<double>& x) {
        double sum = 0;
        for (double v : x) {
            sum += v;
        }
        return sum / x.size();
    }

    static double stddev(const std::vector<double>& x) {
        double m = mean(x);
        double sum = 0;
        for (double v : x) {
            sum += (v - m) * (v - m);
        }
        return sqrt(sum / (x.size() - 1));
    }

    static double lq(const std::vector<double>& x) {
        size_t n = x.size();
        switch (n) {
        case 0:
            return 0;
        }
        std::vector<double> xl(x.begin(), x.begin() + n / 2);
        return median(xl);
    }

    static double uq(const std::vector<double>& x) {
        size_t n = x.size();
        switch (n) {
        case 0:
            return 0;
        }
        std::vector<double> xu(x.begin() + (n + 1) / 2, x.end());
        return median(xu);
    }

    static std::vector<double> out(const std::vector<double>& x) {
        double lqval = lq(x);
        double uqval = uq(x);
        double iqr = uqval - lqval;
        double upper_fence = uqval + 1.5 * iqr;
        double lower_fence = lqval - 1.5 * iqr;

        std::vector<double> outliers;
        for (double v : x) {
            if (v < lower_fence || v > upper_fence) {
                outliers.push_back(v);
            }
        }
        return outliers;
    }
};

