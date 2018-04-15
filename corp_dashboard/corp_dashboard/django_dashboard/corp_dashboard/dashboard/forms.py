from django import forms
from .models import Config
class ConfigForm(forms.ModelForm):
    CONFIG_FILE = forms.CharField(label='CONFIG_FILE', max_length=100)
    AdjacencyList = forms.CharField(label='AdjacencyList', max_length=100)
    GA_SOLUTION_FILE = forms.CharField(label='GA_SOLUTION_FILE', max_length=100)
    CHROMOSOME_FILE = forms.CharField(label='CHROMOSOME_FILE', max_length=100)
    METRIC_OUTPUT = forms.CharField(label='METRIC_OUTPUT', max_length=100)
    GENOTYPE_SIZE = forms.IntegerField(label='GENOTYPE_SIZE')
    STEP_SIZE = forms.IntegerField(label='STEP_SIZE')
    PURGE_DELAY = forms.IntegerField(label='PURGE_DELAY')
    SAMPLE_RATE = forms.IntegerField(label='SAMPLE_RATE')

    class Meta():
        model=Config
        fields=['CONFIG_FILE',
                'AdjacencyList',
                'GA_SOLUTION_FILE',
                'CHROMOSOME_FILE',
                'METRIC_OUTPUT',
                'GENOTYPE_SIZE',
                'STEP_SIZE',
                'PURGE_DELAY',
                'SAMPLE_RATE']
