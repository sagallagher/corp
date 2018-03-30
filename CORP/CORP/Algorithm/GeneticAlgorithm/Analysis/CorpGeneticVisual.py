import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
# class to parse and graph lists outputed from corp project
class CorpGeneticVisual():
    
    def __init__(self, input_file_path):
        self._fitnesses = []
        self._cover_percents = []
        self._num_selecteds = []
        self._colors = []
        self.parse(input_file_path)
   
    # parse data from file into lists
    def parse(self,input_file_path):
        
        data_class = 0
        
        with open(input_file_path, 'r') as f:
            
            for line in f:
                
                if len(line) == 1: 
                    data_class = 0
                
                else:
                    if data_class == 0:
                        self._fitnesses.append(eval(line))
                    elif data_class == 1:
                        self._cover_percents.append(eval(line))
                    elif data_class == 2:
                        self._num_selecteds.append(eval(line))
                    elif data_class == 3:
                        self._colors.append(eval(line))
                        
                    data_class+=1
                  
    def graphAll(self):

        
        generations = [i for i in range(len(self._fitnesses))]
        
        for generation in generations:
            for index in range(len(self._fitnesses[generation])):
                
                #print(generation, self._fitnesses[generation][index])
                plt.scatter(generations[generation],self._fitnesses[generation][index])
                
                #print(generation, self._fitnesses[generation][index])
      
                plt.figure(1)
                plt.subplot(221)
                plt.scatter(generations[generation],self._fitnesses[generation][index])
                
           
                plt.subplot(223)
                plt.scatter(generations[generation],self._cover_percents[generation][index])
                
                plt.subplot(222)
                plt.scatter(generations[generation],self._num_selecteds[generation][index])
                plt.show()        
        
    # graph fitness, cover percent, or number selected   
    # 0 => fitness
    # 1 => cover percent
    # 2 => number selected               
    def graphOne(self, data):

        generations = [i for i in range(len(data))]
        
        for generation in generations:
            for index in range(len(data[generation])):
                
                plt.scatter(generations[generation],data[generation][index])
                
    def graph3D(self,x,y,z,x_label,y_label,z_label):
            
        
        fig = plt.figure()
        ax = fig.add_subplot(111, projection='3d')
        generations = [i for i in range(len(self._fitnesses))]
 
        ax.scatter(x,y,z,c='r', marker='o')

        ax.set_xlabel(x_label)
        ax.set_ylabel(y_label)
        ax.set_zlabel(z_label)

        plt.show()

if __name__ == '__main__':
    
    g = CorpGeneticVisual("C:/Users/Steven/Desktop/metrics.txt")

    # 0 => fitness
    # 1 => cover percent
    # 2 => number selected
    #print(type(g._cover_percents[0][]))
    a = []

    g.graph3D(g._colors,
                     g._num_selecteds,
                     g._fitnesses,
                     'Colors Used',
                     'Number Selected',
                     'Cover Percent')
    


                    