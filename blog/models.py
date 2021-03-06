from django.db import models
from django.conf import settings
from django.utils import timezone
# Create your models here.
class Post(models.Model):
	title = models.CharField(max_length=50)
	author = models.ForeignKey(settings.AUTH_USER_MODEL)
	content = models.TextField()
	created_at = models.DateTimeField(default=timezone.now)


	def __str__(self):
		return self.title
