import { Component, OnInit } from '@angular/core';
import { CommandsService } from "./commands.service";
import * as _ from 'lodash';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})

export class AppComponent implements OnInit {
  public commands: Array<any>;
  public currentCommand: any;
  
  constructor(private commandsService: CommandsService) {
    commandsService.get().subscribe((data: any) => this.commands = data);
    this.currentCommand = this.getDefaultCommand();
  }

  private getDefaultCommand() {
    return {
      id: undefined,
      name: '',
      description: '',
      platform: ''
    }
  }
  
  public createUpdateCommand = function(command: any)  {
    let commandWithId = _.find(this.commands, (el => el.id === command.id));
    if (commandWithId) {
      const updateIndex = _.findIndex(this.commands, { id: commandWithId.id });
      this.commandsService.update(command).subscribe(
        this.commands.splice(updateIndex, 1, command)
      );
    } else {
      this.commandsService.add(command).subscribe(
        commandRecord => {
          command.id = commandRecord.id;
          this.commands.push(command)
        }
      );
    }
    this.currentCommand = this.getDefaultCommand();
  };

  public editCommand = function(record: any) {
    this.currentCommand = record;
  };

  public newCommand = function () {
    this.currentCommand = this.getDefaultCommand();
  };

  public deleteCommand(record) {
    const deleteIndex = _.findIndex(this.commands, { id: record.id });
    this.commandsService.delete(record).subscribe(
      result => this.commands.splice(deleteIndex, 1)
    );
  }

  ngOnInit() { }
}