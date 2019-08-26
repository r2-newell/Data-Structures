package queue;

import java.util.Scanner;

public class Driver {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Queue<String> playList = new Queue<String>(); 
		Scanner input = new Scanner(System.in); 
		String artist_name;
		System.out.println("Enter your favorite artists: "); 
		artist_name = input.nextLine(); 
		while(artist_name.isBlank() != true)
		{
			if(playList.enqueue(artist_name) == true)
				System.out.println(artist_name + " was successfully added to your favorite playlist");
			
			artist_name = input.nextLine();
		}
		
		System.out.println("--------------Playlist-----------"); 
		for(String name : playList)
			System.out.println(name); 
		playList.destroy();
		System.out.println( playList.getSize() + " artistes is in your play list"); 
		input.close(); 
	}
}
