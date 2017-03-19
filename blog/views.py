from django.shortcuts import render
from .models import Post
# Create your views here.
def home(request):
	posts = Post.objects.all()

	return render(request,'blog/home.html',{
		'posts' : posts ,
		})

def post_detail(request,pk):
	post = Post.objects.get(pk = pk)

	return render(request,'blog/post_detail.html',{
		'post' : post ,
		})