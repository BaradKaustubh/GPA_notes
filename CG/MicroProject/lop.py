import pygame
import random
import time

# Modern color scheme
COLOR_RED = (231, 76, 60)      # Pomegranate
COLOR_ORANGE = (230, 126, 34)  # Carrot
COLOR_YELLOW = (241, 196, 15)  # Sun Flower  
COLOR_GREEN = (46, 204, 113)   # Emerald
COLOR_BLUE = (52, 152, 219)    # Peter River
COLOR_INDIGO = (155, 89, 182)  # Amethyst
COLOR_VIOLET = (142, 68, 173)  # Wisteria

# Dynamic window sizing based on screen resolution
display_info = pygame.display.Info()
WINDOW_WIDTH = int(display_info.current_w * 0.8)  # 80% of screen width
WINDOW_HEIGHT = int(WINDOW_WIDTH * 0.75)  # 4:3 aspect ratio

def draw_disk(screen, x, y, size):
    colors = [COLOR_RED, COLOR_ORANGE, COLOR_YELLOW, COLOR_GREEN, COLOR_BLUE, COLOR_INDIGO, COLOR_VIOLET]
    
    # Gradient effect
    for i in range(20):
        color = tuple(max(0, c - i*3) for c in colors[size-1])
        pygame.draw.rect(screen, color, (x - size*int(WINDOW_WIDTH/33), y + i, size*int(WINDOW_WIDTH/16.5), 1))
    
    # Metallic highlights
    for i in range(3):
        pygame.draw.line(screen, (255,255,255), (x - size*int(WINDOW_WIDTH/33) + 5, y + 3 + i), 
                        (x + size*int(WINDOW_WIDTH/33) - 5, y + 3 + i))
    
    # Border effect
    for i in range(2):
        pygame.draw.rect(screen, (255,255,255), 
                        (x - size*int(WINDOW_WIDTH/33) - i, y - i, size*int(WINDOW_WIDTH/16.5) + i*2, 20 + i*2), 1)
    
    # Corner details
    for i in range(5):
        pygame.draw.line(screen, (255,255,255), (x - size*int(WINDOW_WIDTH/33) - 2, y - 2 + i), 
                        (x - size*int(WINDOW_WIDTH/33) + 5, y - 2 + i))
        pygame.draw.line(screen, (255,255,255), (x - size*int(WINDOW_WIDTH/33) - 2 + i, y - 2), 
                        (x - size*int(WINDOW_WIDTH/33) - 2 + i, y + 5))
        pygame.draw.line(screen, (255,255,255), (x + size*int(WINDOW_WIDTH/33) + 2, y - 2 + i), 
                        (x + size*int(WINDOW_WIDTH/33) - 5, y - 2 + i))
        pygame.draw.line(screen, (255,255,255), (x + size*int(WINDOW_WIDTH/33) + 2 - i, y - 2), 
                        (x + size*int(WINDOW_WIDTH/33) + 2 - i, y + 5))

def get_tower_index(x):
    if x < WINDOW_WIDTH/3:
        return 0
    if x < 2*WINDOW_WIDTH/3:
        return 1
    return 2

def get_top_disk(towers, tower):
    for i in range(6, -1, -1):
        if towers[tower][i]:
            return towers[tower][i]
    return 0

def draw_towers(screen, towers, num_disks, move_text, move_count):
    tower_x = [WINDOW_WIDTH//6, WINDOW_WIDTH//2, 5*WINDOW_WIDTH//6]
    tower_base_height = int(WINDOW_HEIGHT * 0.75)
    btn_x = WINDOW_WIDTH - int(WINDOW_WIDTH * 0.2)
    
    # Modern dark background
    screen.fill((34, 47, 62))
    
    # Starfield effect
    for _ in range(int(WINDOW_WIDTH * 0.15)):
        brightness = random.randint(100, 255)
        pygame.draw.circle(screen, (brightness,brightness,brightness), 
                         (random.randint(0,WINDOW_WIDTH), random.randint(0,WINDOW_HEIGHT)), 1)
    
    # Buttons with modern styling
    btn_y = int(WINDOW_HEIGHT * 0.02)
    btn_width = int(WINDOW_WIDTH * 0.18)
    btn_height = int(WINDOW_HEIGHT * 0.055)
    
    # Auto Solve button
    pygame.draw.rect(screen, (46, 204, 113), (btn_x, btn_y, btn_width, btn_height))
    pygame.draw.rect(screen, (255,255,255), (btn_x, btn_y, btn_width, btn_height), 2)
    
    font = pygame.font.SysFont('Arial', int(WINDOW_HEIGHT * 0.044))
    text = font.render('Auto Solve', True, (255,255,255))
    screen.blit(text, (btn_x + btn_width*0.1, btn_y + btn_height*0.15))
    
    # Reset button
    btn_y += int(btn_height * 1.3)
    pygame.draw.rect(screen, (231, 76, 60), (btn_x, btn_y, btn_width, btn_height))
    pygame.draw.rect(screen, (255,255,255), (btn_x, btn_y, btn_width, btn_height), 2)
    
    text = font.render('Reset', True, (255,255,255))
    screen.blit(text, (btn_x + btn_width*0.25, btn_y + btn_height*0.15))
    
    # Draw towers
    for i in range(3):
        # Base
        pygame.draw.rect(screen, (189, 195, 199), 
                        (tower_x[i]-int(WINDOW_WIDTH*0.068), tower_base_height, 
                         int(WINDOW_WIDTH*0.136), int(WINDOW_HEIGHT*0.045)))
        
        # Pole
        pygame.draw.rect(screen, (189, 195, 199), 
                        (tower_x[i]-int(WINDOW_WIDTH*0.015), WINDOW_HEIGHT//4, 
                         int(WINDOW_WIDTH*0.03), tower_base_height-WINDOW_HEIGHT//4))
        
        # Top cap
        pygame.draw.rect(screen, (189, 195, 199), 
                        (tower_x[i]-int(WINDOW_WIDTH*0.03), WINDOW_HEIGHT//4-15, 
                         int(WINDOW_WIDTH*0.06), 15))
        
        # Draw disks
        for j in range(num_disks):
            if towers[i][j]:
                draw_disk(screen, tower_x[i], tower_base_height-35-j*28, towers[i][j])
        
        # Tower labels
        text = font.render(f'Tower {chr(65+i)}', True, (255,255,255))
        label_width = int(WINDOW_WIDTH * 0.12)
        pygame.draw.rect(screen, (255,255,255), 
                        (tower_x[i]-label_width//2, tower_base_height+35, label_width, btn_height), 1)
        screen.blit(text, (tower_x[i]-label_width//2+5, tower_base_height+40))
    
    # Move text
    text = font.render(move_text, True, (241, 196, 15))
    msg_width = int(WINDOW_WIDTH * 0.6)
    pygame.draw.rect(screen, (241, 196, 15), 
                    (WINDOW_WIDTH//2-msg_width//2, int(WINDOW_HEIGHT*0.07), msg_width, btn_height), 1)
    screen.blit(text, (WINDOW_WIDTH//2-msg_width//2+10, int(WINDOW_HEIGHT*0.08)))
    
    # Move counter
    text = font.render(f'Moves: {move_count}', True, (255,255,255))
    pygame.draw.rect(screen, (255,255,255), 
                    (10, 10, int(WINDOW_WIDTH*0.17), btn_height), 1)
    screen.blit(text, (15, 15))

def is_move_valid(towers, from_tower, to_tower, disk):
    top_disk = get_top_disk(towers, to_tower)
    return top_disk == 0 or top_disk > disk

def move_disk(towers, from_tower, to_tower, disk):
    for i in range(7):
        if towers[from_tower][i] == disk:
            towers[from_tower][i] = 0
            break
    
    for i in range(7):
        if towers[to_tower][i] == 0:
            towers[to_tower][i] = disk
            break

def solve_tower_of_hanoi(screen, towers, n, from_tower, to_tower, aux_tower, num_disks, move_count):
    if n == 1:
        disk = get_top_disk(towers, from_tower)
        move_disk(towers, from_tower, to_tower, disk)
        move_count[0] += 1
        msg = f"Auto-moving disk from Tower {chr(65+from_tower)} to {chr(65+to_tower)}"
        draw_towers(screen, towers, num_disks, msg, move_count[0])
        pygame.display.flip()
        time.sleep(0.8)
        return
    
    solve_tower_of_hanoi(screen, towers, n-1, from_tower, aux_tower, to_tower, num_disks, move_count)
    solve_tower_of_hanoi(screen, towers, 1, from_tower, to_tower, aux_tower, num_disks, move_count)
    solve_tower_of_hanoi(screen, towers, n-1, aux_tower, to_tower, from_tower, num_disks, move_count)

def main():
    while True:
        try:
            num_disks = int(input("Enter number of disks (1-7): "))
            if 1 <= num_disks <= 7:
                break
            print("Invalid input! Please enter 1-7 disks.")
        except ValueError:
            print("Please enter a valid number.")
    
    # Initialize pygame and check for errors
    if pygame.init()[1] > 0:
        print(f"Warning: {pygame.init()[1]} pygame modules failed to initialize")
    
    # Initialize video system specifically and check for errors
    if pygame.display.init():
        screen = pygame.display.set_mode((WINDOW_WIDTH, WINDOW_HEIGHT))
        pygame.display.set_caption("Tower of Hanoi")
    else:
        print("Error: Could not initialize pygame display")
        return
    
    towers = [[0]*7 for _ in range(3)]
    for i in range(num_disks):
        towers[0][i] = num_disks - i
    
    move_count = 0
    selected_tower = -1
    
    draw_towers(screen, towers, num_disks, "Click source and destination towers", move_count)
    pygame.display.flip()
    
    running = True
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            
            if event.type == pygame.MOUSEBUTTONDOWN and event.button == 1:
                x, y = event.pos
                btn_width = int(WINDOW_WIDTH * 0.18)
                btn_height = int(WINDOW_HEIGHT * 0.055)
                btn_x = WINDOW_WIDTH - int(WINDOW_WIDTH * 0.2)
                
                if btn_x <= x <= btn_x + btn_width:
                    if int(WINDOW_HEIGHT * 0.02) <= y <= int(WINDOW_HEIGHT * 0.02) + btn_height:
                        towers = [[0]*7 for _ in range(3)]
                        for i in range(num_disks):
                            towers[0][i] = num_disks - i
                        move_count = [0]
                        selected_tower = -1
                        solve_tower_of_hanoi(screen, towers, num_disks, 0, 2, 1, num_disks, move_count)
                        move_count = move_count[0]
                        continue
                    
                    if int(WINDOW_HEIGHT * 0.02) + btn_height*1.3 <= y <= int(WINDOW_HEIGHT * 0.02) + btn_height*2.3:
                        towers = [[0]*7 for _ in range(3)]
                        for i in range(num_disks):
                            towers[0][i] = num_disks - i
                        move_count = 0
                        selected_tower = -1
                        draw_towers(screen, towers, num_disks, "Game Reset! Click source and destination towers", move_count)
                        pygame.display.flip()
                        continue
                
                clicked_tower = get_tower_index(x)
                
                if selected_tower == -1:
                    top_disk = get_top_disk(towers, clicked_tower)
                    if top_disk > 0:
                        selected_tower = clicked_tower
                        msg = f"Selected Tower {chr(65+clicked_tower)}"
                        draw_towers(screen, towers, num_disks, msg, move_count)
                        pygame.display.flip()
                else:
                    disk = get_top_disk(towers, selected_tower)
                    if is_move_valid(towers, selected_tower, clicked_tower, disk):
                        move_disk(towers, selected_tower, clicked_tower, disk)
                        move_count += 1
                        msg = f"Moved disk from Tower {chr(65+selected_tower)} to {chr(65+clicked_tower)}"
                        draw_towers(screen, towers, num_disks, msg, move_count)
                        pygame.display.flip()
                    selected_tower = -1
        
        if towers[2][num_disks-1] != 0:
            # Victory celebration
            for _ in range(50):
                x = random.randint(0, WINDOW_WIDTH)
                y = random.randint(0, WINDOW_HEIGHT)
                color = (random.randint(100,255), random.randint(100,255), random.randint(100,255))
                pygame.draw.circle(screen, color, (x,y), random.randint(2,8))
                pygame.display.flip()
                time.sleep(0.02)
            
            font = pygame.font.SysFont('Arial', int(WINDOW_HEIGHT * 0.065))
            text = font.render(f"Puzzle Completed in {move_count} Moves!", True, (241, 196, 15))
            msg_width = int(WINDOW_WIDTH * 0.75)
            pygame.draw.rect(screen, (241, 196, 15), 
                           (WINDOW_WIDTH//2-msg_width//2, int(WINDOW_HEIGHT*0.16), msg_width, int(WINDOW_HEIGHT*0.073)), 1)
            screen.blit(text, (WINDOW_WIDTH//2-msg_width//2+10, int(WINDOW_HEIGHT*0.17)))
            pygame.display.flip()
            
            while True:
                for event in pygame.event.get():
                    if event.type == pygame.QUIT:
                        running = False
                        break
                if not running:
                    break
                time.sleep(0.03)
    
    pygame.quit()

if __name__ == "__main__":
    main()
