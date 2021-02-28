import { Component, OnInit, Input, Output, EventEmitter } from '@angular/core';

@Component({
  selector: 'app-commands-list',
  templateUrl: './commands-list.component.html',
  styleUrls: ['./commands-list.component.css']
})
export class CommandsListComponent implements OnInit {
  @Input() commands: Array<any>;
  @Output() recordDeleted = new EventEmitter<any>();
  @Output() newClicked = new EventEmitter<any>();
  @Output() editClicked = new EventEmitter<any>();

  public delete = (data) => this.recordDeleted.emit(data);
  public new = () => this.newClicked.emit();
  public edit = (data) => this.editClicked.emit(data);

  ngOnInit(): void {}
}
