from django.shortcuts import render,redirect
from django.template import loader
# Create your views here.
from django.http import HttpResponse
from .forms import ConfigForm

def index(request):
    return HttpResponse("Hello, world. You're at the polls index.")

def dashboard(request):

    context = {}
    template = loader.get_template('dashboard/index.html')
    return HttpResponse(template.render(context, request))

def success(request):
    context={a:pk}
    template = loader.get_template('dashboard/success.html')
    return HttpResponse(template.render(context, request))

def add_new_config(request):

    # write the values to the confile file
    def write_model_to_textfile(post):

        # create new file with that name

        # write the values to a file
        with open(vars(post)["CONFIG_FILE"]) as f:
            for key, value in vars(post):
                f.write('%s=%s' % (key,value))

    # if this is a POST request we need to process the form data
    if request.method == 'POST':
        # create a form instance and populate it with data from the request:
        formset = ConfigForm(request.POST)

        # check whether it's valid:
        if formset.is_valid():

            post = formset.save()

            write_model_to_textfile(post)

            return render(request, 'dashboard/success.html', {'formset': formset})

    # if a GET (or any other method) we'll create a blank form
    else:
        formset = ConfigForm()

    return render(request, 'dashboard/success.html', {'formset': formset})
