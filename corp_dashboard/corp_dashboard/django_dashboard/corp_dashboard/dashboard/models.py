from django.db import models

# Create your models here.
class Config(models.Model):
    AdjacencyList = models.CharField(max_length=200)
    GA_SOLUTION_FILE = models.CharField(max_length=200)
    CHROMOSOME_FILE = models.CharField(max_length=200)
    METRIC_OUTPUT = models.CharField(max_length=200)
    GENOTYPE_SIZE = models.IntegerField(default=10)
    STEP_SIZE = models.IntegerField(default=1)
    PURGE_DELAY = models.IntegerField(default=10000)
    SAMPLE_RATE = models.IntegerField(default=10000)
