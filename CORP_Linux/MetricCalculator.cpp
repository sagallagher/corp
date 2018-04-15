#include"MetricCalculator.h"
#include"ColoringFitness.h"
#include<fstream>
MetricCalculator::MetricCalculator(Genotype& genotype) : _genotype { genotype } {}


std::vector<double> MetricCalculator::getMetric(int metric_num)
{
  std::vector<double> result;
  ColoringFitness  cf;
  for (Chromosome chromo : _genotype.getChromosomes())
    if(metric_num == 0) result.push_back(chromo.getFitness());
    else if(metric_num == 1) result.push_back((double)chromo.getCover()._bitVector.numberSelected());
    else if(metric_num == 2) result.push_back(chromo.getCover().coverPercent());
    else if(metric_num == 3) result.push_back(cf.getChromaticNumber(chromo));

  return result;
}


bool MetricCalculator::writeVectorAsList(std::vector<double>& metric ,std::string outfile_path)
{
  std::ofstream outfile;

  outfile.open(outfile_path, std::ios_base::app);

  if (!outfile)
  {
    std::cout << "Metric outputfile not found\n";
    return false;
  }


  // prepare to write fitness list []
  outfile << "[";

  int index = 0;

  // write fitness list
  for (auto item : metric)
  {
    // write the the item
    outfile << item;

    // followed by a comma
    // unlesss its the last item
    if (index < metric.size()-1) outfile << ",";


    // increment index to track where in list we are
    index++;
  }

  // end fitness list
  outfile << "]\n";

  outfile.close();
}

bool MetricCalculator::writeMetrics(std::vector<std::vector<double>> metrics, std::string outfile_path)
{
  for(auto metric : metrics)
    writeVectorAsList(metric, outfile_path);
}

bool MetricCalculator::writeAll(std::string outfile_path)
{
  const int METRIC_COUNT = 3;

  for(int i = 0; i <= METRIC_COUNT;i++)
  {
    std::vector<double> metric = getMetric(i);
    writeVectorAsList(metric, outfile_path);
  }

  std::ofstream out(outfile_path, std::ios_base::app);
  out << "\n";
  out.close();
}
