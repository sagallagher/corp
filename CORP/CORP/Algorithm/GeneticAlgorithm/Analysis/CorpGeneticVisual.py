import matplotlib.pyplot as plt

# class to parse and graph lists outputed from corp project
class CorpGeneticVisual():
    
    def __init__(self, input_file_path):
        self._fitnesses = []
        self._cover_percents = []
        self._num_selecteds = []
        
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
                        
                    data_class+=1
     
    # graph fitness, cover percent, or number selected   
    # 0 => fitness
    # 1 => cover percent
    # 2 => number selected               
    def graph(self, metric):

        data = []
        
        if metric == 0: data = self._fitnesses
        elif metric == 1: data = self._cover_percents
        elif metric == 2: data = self._num_selecteds
        
        generations = [i for i in range(len(data))]
        
        for generation in generations:
            for index in range(len(data[generation])):
                
                #print(generation, self._fitnesses[generation][index])
                plt.scatter(generations[generation],data[generation][index])
     
    

if __name__ == '__main__':
    
    g = CorpGeneticVisual("C:/Users/Steven/Desktop/metrics.txt")

    # 0 => fitness
    # 1 => cover percent
    # 2 => number selected
    
    g.graph(1)

                    