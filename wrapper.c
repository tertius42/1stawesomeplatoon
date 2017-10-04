#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char * argv[]) {
	FILE * wget = NULL;
	FILE * fb2rss = NULL;
	FILE * git = NULL;
	while (1) {
		wget = popen("wget -U \"Mozzila/5.0\" \"https://www.facebook.com/1stawesomeplatoon/posts\" -Oposts.html", "r");
		if (!wget) {
			fprintf(stderr, "error: wget isn't available\n");
			return 0;
		}
		pclose(wget);

		printf("converting...");
		fb2rss = popen("fb2rss posts.html -oposts.xml", "r");
		if (!fb2rss) {
			fprintf(stderr, "error: fb2rss isn't available\n");
			return 0;
		}
		pclose(fb2rss);

		printf("commiting...");
		git = popen("git commit -a -m \"auto-commit by wrapper\"", "r");
		if (!git) {
			fprintf(stderr, "error: git isn't available\n");
			return 0;
		}
		pclose(git);

		printf("pushing...");
		git = popen("git push", "r");
		if (!git) {
			fprintf(stderr, "error: git isn't available\n");
			return 0;
		}
		pclose(git);
		printf("done!");

		sleep(60);
	}

	return 0;
}
