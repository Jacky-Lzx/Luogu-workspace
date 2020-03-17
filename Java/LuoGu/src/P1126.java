import java.util.ArrayList;
import java.util.Scanner;

enum direction
{
	E, S, W, N;
}
class Point
{
	Point(int x, int y, direction dir)
	{
		this.x = x;
		this.y = y;
		this.dir = dir;
	}
	public int x;
	public int y;
	public direction dir;
}

public class P1126
{
	static int[][] steps;
	static int N, M;
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		N = input.nextInt();
		M = input.nextInt();
		
		int[][] array = new int[N][M];
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				array[i][j] = input.nextInt();
		
		Point start = new Point(input.nextInt(), input.nextInt(), direction.W);
		Point end = new Point(input.nextInt(), input.nextInt(), direction.W);
		
		direction startD = null;
		
		switch(input.next())
		{
		case "E":
			startD = direction.E;
			break;
		case "W":
			startD = direction.W;
			break;
		case "N":
			startD = direction.N;
			break;
		case "S":
			startD = direction.S;
			break;
		}
		start.dir = startD;
		
		input.close();
		
		
		steps = new int[N][M];
		steps[start.x][start.y] = 0;
		
		ArrayList<Point> queue = new ArrayList<>();
		
		queue.add(start);
		
		while (queue.size() != 0)
		{
			Point current = queue.get(0);
			queue.remove(0);
			
//			if (current.x == end.x && current.y == end.y)
//				break;
			
//			calculate(direction.E, current, queue);
//			calculate(direction.S, current, queue);
//			calculate(direction.W, current, queue);
//			calculate(direction.N, current, queue);
			switch(current.dir)
			{
			case E:
				//  everytime check validation
				for (int i = 3; i > 0; i--)
				{
					// direction.E
					if (current.y + i < M)
					{
						if (steps[current.x][current.y + i] != 0 && steps[current.x][current.y + i] > steps[current.x][current.y] + 1)
						{
							steps[current.x][current.y + i] = steps[current.x][current.y] + 1;
							queue.add(new Point(current.x, current.y + i, direction.E));
						}
					}
					//deirection.S
					if (current.x + i < N)
					{
						
					}
				}
			case W:
				
			case N:
				
			case S:
			}
			
			
		}
		
	}
	
	public static void calculate(direction dir, Point current, ArrayList<Point> queue)
	{
		int turnStep = 0;
		switch(dir)
		{
		case W:
			if (current.dir == direction.N || current.dir == direction.S)
				turnStep = 1;
			else if (current.dir == direction.E)
				turnStep = 2;
			
			//start from +3 to +1
			// if is a valid position
			//	 if current steps value is larger than calculated, replace it
			
		case E:
			
		case N:
			
		case S:
			if (current.x + 3 < N)
			{
				if (steps[current.x + 3][current.y] != 0 && steps[current.x + 3][current.y] > steps[current.x][current.y] + 1)
				{
					steps[current.x + 3][current.y] = steps[current.x][current.y] + 1;
					queue.add(new Point(current.x + 3, current.y, direction.S));
				}
			}
			
			if (current.x + 2 < N)
			{
				steps[current.x + 2][current.y] = steps[current.x][current.y] + 1;
				queue.add(new Point(current.x + 2, current.y, direction.S));
			}
			if (current.x + 1 < N)
			{
				steps[current.x + 1][current.y] = steps[current.x][current.y] + 1;
				queue.add(new Point(current.x + 1, current.y, direction.S));
			}
		}
	}
}