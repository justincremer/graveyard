import { Component, OnInit, Output, EventEmitter, Input } from '@angular/core';

@Component({
  selector: 'app-add-update-commands',
  templateUrl: './add-update-commands.component.html',
  styleUrls: ['./add-update-commands.component.css']
})
export class AddUpdateCommandsComponent implements OnInit {
  @Output() commandCreated = new EventEmitter<any>();
  @Input() command: any;

  constructor() {
    this.clearCommands();
  }

  ngOnInit(): void {}

  private clearCommands = () => {
    this.command = {
      id: null,
      name: '',
      description: '',
      platform: ''
    };
  }

  public addUpdateCommand = (event) => {
    this.commandCreated.emit(this.command);
    this.clearCommands();
  }
}
