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
    print("ZZZ")
    # if this is a POST request we need to process the form data
    if request.method == 'POST':
        # create a form instance and populate it with data from the request:
        formset = ConfigForm(request.POST)
        print("ASDSDA")
        print(formset)
        # check whether it's valid:
        if formset.is_valid():
            print("EHHH")
            # process the data in form.cleaned_data as required
            # ...
            # redirect to a new URL:
            post = formset.save()

            print(post.AdjacencyList)




            return render(request, 'dashboard/success.html', {'formset': formset})

    # if a GET (or any other method) we'll create a blank form
    else:
        print("AHHH")
        formset = ConfigForm()
        print("AHHH")
    print("YYY")
    return render(request, 'dashboard/success.html', {'formset': formset})

def a(request):

    form = ConfigForm()
    return render(request, '/',{'forms' :form})
